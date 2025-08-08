class EightQueensSolver:
    """
    使用回溯算法解决八皇后问题的类。
    """
    def __init__(self):
        # n 表示棋盘的大小和皇后的数量
        self.n = 8
        # solutions 用来存储所有找到的解
        self.solutions = []
        # col_placement[row] = col 表示在第 row 行的第 col 列放置了一个皇后
        # 初始化为 -1，表示所有行都还没有放置皇后
        self.col_placement = [-1] * self.n

    def solve(self):
        """
        公开的启动方法，开始从第 0 行解决问题。
        """
        # 从第 0 行开始递归放置皇后
        self._place_queen_in_row(0)
        return self.solutions

    def _place_queen_in_row(self, row):
        """
        递归函数，尝试在指定的行（row）中放置一个皇后。
        """
        # 基线条件（Base Case）：如果成功放置到第 n 行（即所有行都已放好）
        # 说明我们找到了一个完整的解
        if row == self.n:
            # 格式化并保存当前解
            self.solutions.append(self._format_board())
            return

        # 尝试在当前行的每一列（0 到 n-1）中放置皇后
        for col in range(self.n):
            # 检查在 (row, col) 位置放置皇后是否安全
            if self._is_safe(row, col):
                # 如果安全，则在此处放置皇后
                self.col_placement[row] = col
                
                # 递归地去下一行放置皇后
                self._place_queen_in_row(row + 1)
                
                # 回溯：当从下一行的递归调用返回后，
                # 将当前行的皇后移除，以便尝试当前行的下一个可能位置。
                # 这一步是回溯算法的核心。
                # 在我们的实现中，下一次 for 循环会覆盖 self.col_placement[row] 的值，
                # 所以显式地重置为 -1 不是必需的，但有助于理解。
                self.col_placement[row] = -1

    def _is_safe(self, row, col):
        """
        检查在 (row, col) 位置放置皇后是否会与之前已放置的皇后冲突。
        我们只需要检查前面 0 到 row-1 行的皇后。
        """
        # 遍历之前已经放置了皇后的所有行
        for prev_row in range(row):
            prev_col = self.col_placement[prev_row]

            # 检查列冲突：新的皇后和之前的皇后是否在同一列
            if prev_col == col:
                return False

            # 检查对角线冲突：
            # 如果两个皇后 (row1, col1) 和 (row2, col2) 在对角线上，
            # 那么它们行号之差的绝对值等于列号之差的绝对值。
            # |row - prev_row| == |col - prev_col|
            if abs(row - prev_row) == abs(col - prev_col):
                return False
        
        # 如果没有发现任何冲突，则该位置是安全的
        return True

    def _format_board(self):
        """
        将一维数组表示的解格式化为二维棋盘（用 'Q' 和 '.' 表示）。
        """
        board = []
        for row in range(self.n):
            line = ""
            for col in range(self.n):
                if self.col_placement[row] == col:
                    line += "Q "
                else:
                    line += ". "
            board.append(line.strip())
        return board

# --- 主程序入口 ---
if __name__ == '__main__':
    # 创建求解器实例
    solver = EightQueensSolver()
    
    # 求解
    all_solutions = solver.solve()
    
    # 打印结果
    print(f"八皇后问题总共找到了 {len(all_solutions)} 个不同的解。\n")
    
    # 为了避免输出过多，只展示前 5 个解作为示例
    print("--- 展示前 5 个解法 ---")
    for i, solution_board in enumerate(all_solutions[:5]):
        print(f"\n解法 {i + 1}:")
        for row_str in solution_board:
            print(row_str)