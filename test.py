import os

# 定义模板内容映射
# <% tp.file.cursor() %> 是 Obsidian Templater 的光标占位符，对应 VS Code 的 $1, $2
templates = {
    "blue.md": '<div class="blue-highlight">\n<% tp.file.cursor() %>\n</div>', # 对应蓝色高亮 
    "green.md": '<div class="green-highlight">\n<% tp.file.cursor() %>\n</div>', # 对应绿色高亮 
    "cpp.md": '```cpp\n<% tp.file.cursor() %>\n```', # 对应 C++ 代码块 
    "newline.md": '<br>\n\n<% tp.file.cursor() %>', # 对应强制换行 
    "color_block.md": '<div style="color: red;">\n<% tp.file.cursor() %>\n</div>', # 对应整块上色 [cite: 5, 6]
    "font_text.md": '<span style="color: red;"><% tp.file.cursor() %></span>', # 对应彩色字体 
    "golink.md": '[点击跳转到<% tp.file.cursor() %>](#id名)', # 对应跳转链接 
    "goanchor.md": '<a id="<% tp.file.cursor() %>"></a>' # 对应锚点定义 
}

def create_templates():
    output_dir = "Obsidian_Templates"
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
        print(f"创建文件夹: {output_dir}")

    for filename, content in templates.items():
        filepath = os.path.join(output_dir, filename)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
        print(f"已生成模板: {filename}")

if __name__ == "__main__":
    create_templates()