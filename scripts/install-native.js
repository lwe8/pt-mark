const fs = require("fs");
const path = require("path");
const { spawnSync } = require("child_process");

const rootDir = path.resolve(__dirname, "..");
const distBinary = path.join(rootDir, "dist", "ptmark.node");
const buildBinary = path.join(rootDir, "build", "Release", "ptmark.node");

if (fs.existsSync(distBinary)) {
  console.log("[my-julian] Using prebuilt native binary from dist/ptmark.node");
  process.exit(0);
}

console.log("[my-julian] Prebuilt binary not found. Building with node-gyp...");

const gypCommand = process.env.npm_config_node_gyp || "node-gyp";
const buildResult = spawnSync(gypCommand, ["rebuild"], {
  cwd: rootDir,
  stdio: "inherit",
  shell: process.platform === "win32"
});

if (buildResult.status !== 0) {
  process.exit(buildResult.status || 1);
}

if (!fs.existsSync(buildBinary)) {
  console.error("[my-julian] Build completed but build/Release/ptmark.node was not found.");
  process.exit(1);
}

fs.mkdirSync(path.join(rootDir, "dist"), { recursive: true });
fs.copyFileSync(buildBinary, distBinary);

console.log("[my-julian] Built native binary and copied it to dist/ptmark.node");