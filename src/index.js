let ptmark;

try {
  ptmark = require("../build/Release/ptmark.node");
} catch (buildError) {
  try {
    ptmark = require("../dist/ptmark.node");
  } catch (distError) {
    const error = new Error(
      "Failed to load native addon. Tried build/Release/ptmark.node and dist/ptmark.node."
    );
    error.cause = { buildError, distError };
    throw error;
  }
}

module.exports = ptmark;