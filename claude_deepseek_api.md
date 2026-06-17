### Claude Code 接入 DeepSeek API 本地部署标准流程

针对无科学上网环境、无预装基础依赖的 Windows 系统，完整的国内直连部署流程如下：

#### 1. 基础环境安装（国内直连方案）

打开 CMD 命令提示符，逐行执行以下命令。该步骤通过官方安装包与国内镜像源直接下载，并静默完成 Node.js 与 Git 的安装。

**安装 Node.js：**

```cmd
curl -L -o node-setup.msi https://nodejs.org/dist/v20.18.0/node-v20.18.0-x64.msi
msiexec /i node-setup.msi /quiet /norestart

```
要是后面npm失败就是node.js没有安装好,但是应该下载好了,直接在电脑搜node.js的msi,都选默认的,会自动添加到系统路径,之后就可以用npm命令了

**安装 Git：**

```cmd
curl -L -o Git-Setup.exe https://npmmirror.com/mirrors/git-for-windows/v2.45.2.windows.1/Git-2.45.2-64-bit.exe
Git-Setup.exe /VERYSILENT /NORESTART

```

*注意：以上命令执行完毕后，**必须关闭当前 CMD 窗口并重新打开**，以刷新系统环境变量。*

#### 2. 工具安装（配置国内镜像源）

在新打开的 CMD 窗口中，先将 npm 的下载源切换至国内节点（解决下载转圈卡死问题），随后安装 Claude Code。

```cmd
npm config set registry https://registry.npmmirror.com
npm install -g @anthropic-ai/claude-code

```

#### 3. DeepSeek API 永久环境变量配置

继续在当前 CMD 窗口中执行以下 `setx` 命令。这会将配置永久写入 Windows 系统环境变量（请确保替换第二行的真实 API Key，并保留双引号）。

```cmd
setx ANTHROPIC_BASE_URL "https://api.deepseek.com/anthropic"
setx ANTHROPIC_AUTH_TOKEN "这里替换为真实的API_Key"
setx ANTHROPIC_MODEL "deepseek-v4-pro[1m]"
setx ANTHROPIC_DEFAULT_OPUS_MODEL "deepseek-v4-pro[1m]"
setx ANTHROPIC_DEFAULT_SONNET_MODEL "deepseek-v4-pro[1m]"
setx ANTHROPIC_DEFAULT_HAIKU_MODEL "deepseek-v4-flash"
setx CLAUDE_CODE_SUBAGENT_MODEL "deepseek-v4-flash"
setx CLAUDE_CODE_EFFORT_LEVEL "max"

```

#### 4. 重启生效与日常使用

1. **彻底关闭**当前所有 CMD 窗口或终端。
2. 在任意目标代码文件夹中，右键打开终端或在路径栏输入 `cmd` 打开。
3. 输入 `claude` 并回车，即可直接进入交互界面并调用 DeepSeek 模型处理当前目录代码。后续使用均无需重新配置。
在打开任务管理器时输入claude --dangerously-skip-permissions应该可以在这次对话中,不用一直按yes,但是永久的话需要另外操作
<br>

<div class="green-highlight">
goodnotes
</div>
<br>
