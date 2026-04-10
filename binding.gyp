{
    "targets": [
        {
            "target_name": "ptmark",
            "sources": [ "src/main.cpp" ],
            "cflags_cc": [ "-std=c++20", "-fexceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "xcode_settings": {
                "GCC_ENABLE_CPP_EXCEPTIONS": "YES"
            },
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "ExceptionHandling": 1
                }
            },
            "node_module_path": "./dist/ptmark.node"
        }
    ]
} # type: ignore