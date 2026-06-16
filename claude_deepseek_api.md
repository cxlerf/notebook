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

<div class="blue-highlight">
goodnotes可以填充几何图形吗,比如把一个三角形内部填满浅蓝色
</div>
<br>

# Goodnotes 6 笔记技巧：图形填充与无边框色块制作

## 一、 如何给几何图形填充颜色（如浅蓝色）

在 Goodnotes 中，有两种常用方法可以实现内部半透明颜色的自动填充：

**方法 1：使用“形状工具”（推荐）**

1. 选中顶部工具栏的**形状工具**（圆形/三角形/方形图标）。
2. 再次点击该图标展开菜单，开启“填充颜色”选项。
3. 在调色板选择所需颜色（如浅蓝色）。
4. 一笔画出闭合图形（如三角形），停顿片刻，系统会自动规整并填充半透明颜色。


---

## 二、 进阶技巧：如何去除边框，只保留纯色块

在 Goodnotes 6 中，想要去掉外围的实线边框，仅保留内部的纯色填充，有以下几种方案：

**✨ 最优解（官方原生功能）**

1. 正常画出带有边框和填充色的图形。
2. 使用**套索工具**圈住整个图形。
3. 点击选中的区域，在弹出的菜单中找到**笔画设置**。
4. 将笔画（边框）选项设置为“无”。
*优势：操作最快，且保留了图形属性，后续可随时恢复边框或更改颜色。*
