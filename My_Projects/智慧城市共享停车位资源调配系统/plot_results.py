import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# ======= 1. 结果数据 =======
Q1_USERS, Q1_DIST = 300, 2.82
Q2_USERS, Q2_DIST = 200, 9.45
Q3_USERS, Q3_DIST = 200, 9.47

# ======= 2. 稳健读取 CSV 函数 =======
def load_csv(filename):
    for enc in ['utf-8', 'gbk', 'utf-8-sig', 'latin1']:
        try:
            df = pd.read_csv(filename, encoding=enc)
            print(f"成功读取 {filename}，编码为: {enc}")
            return df
        except:
            continue
    return None

spots = load_csv('spots.csv')
users = load_csv('users.csv')
alloc = load_csv('q3_allocations.csv')

# ======= 3. 字体与风格设置 =======
plt.rcParams['font.sans-serif'] = ['DejaVu Sans', 'Arial', 'sans-serif']
plt.rcParams['axes.unicode_minus'] = False
sns.set_theme(style="whitegrid")

if spots is None or users is None or alloc is None:
    print("错误：无法读取数据文件，请确保 CSV 文件与脚本在同一文件夹。")
    exit()

# ======= 4. 绘图 =======
fig, axes = plt.subplots(2, 2, figsize=(16, 12))
fig.suptitle('Parking Allocation Analysis Report', fontsize=20)

# --- 图 A: 距离分布 ---
# alloc 列名确定是 dist (C++生成的)
sns.histplot(alloc['dist'], bins=15, kde=True, color='skyblue', ax=axes[0, 0])
axes[0, 0].set_title('User Walking Distance Distribution (Q3)', fontsize=14)
axes[0, 0].set_xlabel('Distance (m)')
axes[0, 0].set_ylabel('Count')

# --- 图 B: 24小时占用趋势 ---
occupancy = []
for h in range(24):
    # 统计 arr <= h < dep 的用户
    count = alloc[(alloc['arr'] <= h) & (alloc['dep'] > h)].shape[0]
    occupancy.append(count)

axes[0, 1].plot(range(24), occupancy, marker='o', color='red', linewidth=2)
axes[0, 1].axhline(y=300, color='black', linestyle='--', label='Total Capacity (300)')
axes[0, 1].fill_between(range(24), occupancy, color='red', alpha=0.1)
axes[0, 1].set_title('24h Parking Occupancy Trend', fontsize=14)
axes[0, 1].set_xlabel('Hour of Day')
axes[0, 1].set_ylabel('Occupied Spots')
axes[0, 1].set_xticks(range(24))
axes[0, 1].legend()

# --- 图 C: 空间分布 (使用列索引防止列名报错) ---
# 假设 spots 第2列是X, 第3列是Y; users 第2列是X, 第3列是Y
try:
    s_x = spots.iloc[:, 1]
    s_y = spots.iloc[:, 2]
    u_x = users.iloc[:, 1]
    u_y = users.iloc[:, 2]
    
    axes[1, 0].scatter(s_x, s_y, c='green', alpha=0.6, s=30, label='Parking Spots', marker='s')
    axes[1, 0].scatter(u_x, u_y, c='blue', alpha=0.2, s=15, label='User Dest.')
    axes[1, 0].set_title('Spatial Distribution', fontsize=14)
    axes[1, 0].set_xlabel('X Coordinate')
    axes[1, 0].set_ylabel('Y Coordinate')
    axes[1, 0].legend()
except:
    axes[1, 0].text(0.5, 0.5, 'Coordinate Error', ha='center')

# --- 图 D: 算法性能对比 ---
labels = ['Q1 (Ideal)', 'Q2 (Offline)', 'Q3 (Online)']
counts = [Q1_USERS, Q2_USERS, Q3_USERS]
dists = [Q1_DIST, Q2_DIST, Q3_DIST]
x = range(len(labels))

ax2 = axes[1, 1].twinx()
axes[1, 1].bar(x, counts, width=0.4, color='teal', alpha=0.7, label='Served Users')
ax2.plot(x, dists, marker='D', color='orange', linewidth=2, label='Avg Dist')

axes[1, 1].set_xticks(x)
axes[1, 1].set_xticklabels(labels)
axes[1, 1].set_ylabel('User Count', color='teal')
ax2.set_ylabel('Avg Distance (m)', color='orange')
axes[1, 1].set_title('Algorithm Performance Comparison', fontsize=14)

# ======= 5. 保存并导出 =======
plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.savefig('report_charts.png', dpi=300)
print("\n" + "="*40)
print("成功！图表已保存为 'report_charts.png'")
print("请在 VSCode 左侧文件列表中打开查看。")
print("="*40)