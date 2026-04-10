# ptmark

A simple Markdown-to-HTML parser implemented as a native Node.js C++ addon, based on [Maddy][maddy], a header-only C++ Markdown-to-HTML parser library.

## Install

```sh
npm i pt-mark
```

## Use

```js
const ptmark = require("pt-mark"); // commonjs
import ptmark from "pt-mark"; // esm / typescript
```

## API

1. `fromContent(markdown, [config])` : Markdown content to HTML string.
2. `fromFile(filePath, [config])` : Markdown file to HTML string.
3. `fromFileToFile(inputFilePath, outFilePath, [config])` : Markdown file to HTML file.

## License

[Apache-2.0][license] © [Pho Thin Maung][ptm]

Most parts of the Markdown-to-HTML parser in ptmark are derived from
[Maddy][maddy], which is licensed under the MIT License ([see license][maddy-license]).
This project adds new features and modifications to several of the original
parsers.

<!-- markdownlint-disable MD053 -->

[license]: LICENSE
[ptm]: https://github.com/phothinmg
[maddy]: https://github.com/progsource/maddy
[maddy-license]: https://github.com/progsource/maddy/blob/master/LICENSE
