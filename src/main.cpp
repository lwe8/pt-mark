#include <node.h>
#include <string>
#include <vector>
#include <cmath>
#include <optional>

#include "../ptmark/ptmark.hpp"

namespace ptmark
{

    void FromContent(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        if (args.Length() < 1 || args.Length() > 2 || !args[0]->IsString())
        {
            isolate->ThrowException(v8::Exception::TypeError(
                v8::String::NewFromUtf8Literal(isolate, "Usage: fromContent(markdown, [config])")));
            return;
        }

        v8::String::Utf8Value utf8(isolate, args[0]);
        std::string mdContent = *utf8 ? *utf8 : "";

        std::shared_ptr<maddy::ParserConfig> config = nullptr;

        if (args.Length() > 1 && !args[1]->IsUndefined() && !args[1]->IsNull())
        {
            if (!args[1]->IsObject())
            {
                isolate->ThrowException(v8::Exception::TypeError(
                    v8::String::NewFromUtf8Literal(isolate, "config must be an object")));
                return;
            }

            auto obj = args[1].As<v8::Object>();
            config = std::make_shared<maddy::ParserConfig>();

            auto kInline = v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled");
            auto kEnabled = v8::String::NewFromUtf8Literal(isolate, "enabledParsers");

            v8::Local<v8::Value> v;

            if (obj->Get(context, kInline).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsBoolean())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled must be boolean")));
                    return;
                }
                config->isHeadlineInlineParsingEnabled = v->BooleanValue(isolate);
            }

            if (obj->Get(context, kEnabled).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsUint32())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "enabledParsers must be uint32")));
                    return;
                }
                config->enabledParsers =
                    v->Uint32Value(context).FromMaybe(maddy::types::DEFAULT);
            }
        }

        std::string html = ptmark::parser::fromContent(mdContent, config);
        args.GetReturnValue().Set(
            v8::String::NewFromUtf8(isolate, html.c_str(), v8::NewStringType::kNormal).ToLocalChecked());
    }
    void FromFileToFile(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        if (args.Length() < 2 || args.Length() > 3 || !args[0]->IsString() || !args[1]->IsString())
        {
            isolate->ThrowException(v8::Exception::TypeError(
                v8::String::NewFromUtf8Literal(isolate, "Usage: fromFileToFile(inputFilePath, outFilePath, [config])")));
            return;
        }

        v8::String::Utf8Value input_file(isolate, args[0]);
        std::string inputFilePath = *input_file ? *input_file : "";

        v8::String::Utf8Value out_file(isolate, args[1]);
        std::string outFilePath = *out_file ? *out_file : "";

        std::shared_ptr<maddy::ParserConfig> config = nullptr;

        if (args.Length() > 2 && !args[2]->IsUndefined() && !args[2]->IsNull())
        {
            if (!args[2]->IsObject())
            {
                isolate->ThrowException(v8::Exception::TypeError(
                    v8::String::NewFromUtf8Literal(isolate, "config must be an object")));
                return;
            }

            auto obj = args[2].As<v8::Object>();
            config = std::make_shared<maddy::ParserConfig>();

            auto kInline = v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled");
            auto kEnabled = v8::String::NewFromUtf8Literal(isolate, "enabledParsers");

            v8::Local<v8::Value> v;

            if (obj->Get(context, kInline).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsBoolean())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled must be boolean")));
                    return;
                }
                config->isHeadlineInlineParsingEnabled = v->BooleanValue(isolate);
            }

            if (obj->Get(context, kEnabled).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsUint32())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "enabledParsers must be uint32")));
                    return;
                }
                config->enabledParsers =
                    v->Uint32Value(context).FromMaybe(maddy::types::DEFAULT);
            }
        }

        ptmark::parser::fromFileToFile(inputFilePath,outFilePath, config);
        args.GetReturnValue().SetUndefined();
    }
    void FromFile(const v8::FunctionCallbackInfo<v8::Value> &args)
    {
        v8::Isolate *isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        if (args.Length() < 1 || args.Length() > 2 || !args[0]->IsString())
        {
            isolate->ThrowException(v8::Exception::TypeError(
                v8::String::NewFromUtf8Literal(isolate, "Usage: fromFile(filePath, [config])")));
            return;
        }

        v8::String::Utf8Value utf8(isolate, args[0]);
        std::string filePath = *utf8 ? *utf8 : "";

        std::shared_ptr<maddy::ParserConfig> config = nullptr;

        if (args.Length() > 1 && !args[1]->IsUndefined() && !args[1]->IsNull())
        {
            if (!args[1]->IsObject())
            {
                isolate->ThrowException(v8::Exception::TypeError(
                    v8::String::NewFromUtf8Literal(isolate, "config must be an object")));
                return;
            }

            auto obj = args[1].As<v8::Object>();
            config = std::make_shared<maddy::ParserConfig>();

            auto kInline = v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled");
            auto kEnabled = v8::String::NewFromUtf8Literal(isolate, "enabledParsers");

            v8::Local<v8::Value> v;

            if (obj->Get(context, kInline).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsBoolean())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "isHeadlineInlineParsingEnabled must be boolean")));
                    return;
                }
                config->isHeadlineInlineParsingEnabled = v->BooleanValue(isolate);
            }

            if (obj->Get(context, kEnabled).ToLocal(&v) && !v->IsUndefined())
            {
                if (!v->IsUint32())
                {
                    isolate->ThrowException(v8::Exception::TypeError(
                        v8::String::NewFromUtf8Literal(isolate, "enabledParsers must be uint32")));
                    return;
                }
                config->enabledParsers =
                    v->Uint32Value(context).FromMaybe(maddy::types::DEFAULT);
            }
        }

        std::string html = ptmark::parser::fromFile(filePath, config);
        args.GetReturnValue().Set(
            v8::String::NewFromUtf8(isolate, html.c_str(), v8::NewStringType::kNormal).ToLocalChecked());
    }

    void Init(v8::Local<v8::Object> exports, v8::Local<v8::Value> module, void *priv)
    {
        NODE_SET_METHOD(exports, "fromContent", FromContent);
        NODE_SET_METHOD(exports, "fromFile", FromFile);
        NODE_SET_METHOD(exports, "fromFileToFile", FromFileToFile);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, ptmark::Init)
} // namespace ptmark
