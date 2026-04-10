export = Ptmark;
export as namespace ptmark;
declare namespace Ptmark {
  enum PARSER_TYPE {
    NONE = 0,

    BREAKLINE_PARSER = 0b1,
    CHECKLIST_PARSER = 0b10,
    CODE_BLOCK_PARSER = 0b100,
    EMPHASIZED_PARSER = 0b1000,
    HEADLINE_PARSER = 0b10000,
    HORIZONTAL_LINE_PARSER = 0b100000,
    HTML_PARSER = 0b1000000,
    IMAGE_PARSER = 0b10000000,
    INLINE_CODE_PARSER = 0b100000000,
    ITALIC_PARSER = 0b1000000000,
    LINK_PARSER = 0b10000000000,
    ORDERED_LIST_PARSER = 0b100000000000,
    CONFIG_PARSER = 0b1000000000000,
    QUOTE_PARSER = 0b10000000000000,
    STRIKETHROUGH_PARSER = 0b100000000000000,
    STRONG_PARSER = 0b1000000000000000,
    TABLE_PARSER = 0b10000000000000000,
    UNORDERED_LIST_PARSER = 0b100000000000000000,
    LATEX_BLOCK_PARSER = 0b1000000000000000000,

    DEFAULT = 0b0111111111110111111,
    ALL = 0b1111111111111111111,
  }
  interface ParserConfig {
    /**
     * disable headline inline-parsing
     *
     * default: enabled
     */
    isHeadlineInlineParsingEnabled?: boolean;
    /**
     * enabled parsers bitfield
     *
     * default: DEFAULT
     */
    enabledParsers?: PARSER_TYPE;
  }

  function fromContent(mdContent: string, config?: ParserConfig): string;
  function fromFile(filePath: string, config?: ParserConfig): string;
  function fromFileToFile(
    inputFilePath: string,
    outFilePath: string,
    config?: ParserConfig,
  ): string;
}
