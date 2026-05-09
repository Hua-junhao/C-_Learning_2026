import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

# ======= 1. 编码兼容性读取 =======
def smart_read_csv(filename):
    for encoding in['utf-8', 'gbk', 'utf-8-sig']:
        try:
            return pd.read_csv(filename, encoding=encoding)
        except:
            continue
    return None

alloc = smart_read_csv('q3_allocations.csv')
spots = smart_read_csv('spots.csv')
users = smart_read_csv('users.csv')

# ======= 2. 论文级绘图配置 =======
# 使用 DejaVu Sans 确保在 Linux 下不出现中文乱码，采用黑白风格
plt.rcParams['font.family'] = 'DejaVu Sans'
plt.rcParams['axes.unicode_minus'] = False
sns.set_theme(style="ticks") # 论文专用：白底+刻度线

# ======= 3. 绘图与保存 =======

# 图 1: 步行距离分布 (直方图)
plt.figure(figsize=(6, 4))
sns.histplot(alloc['dist'], bins=15, color='white', edgecolor='black', linewidth=1.5)
plt.title('Fig 1: Walking Distance Distribution', fontsize=12, fontweight='bold')
plt.xlabel('Distance (m)')
plt.ylabel('User Count')
plt.savefig('Fig1_Distance.png', dpi=300, bbox_inches='tight')

# 图 2: 24小时停车趋势 (面积图)
plt.figure(figsize=(6, 4))
occupancy = [alloc[(alloc['arr'] <= h) & (alloc['dep'] > h)].shape[0] for h in range(24)]
plt.plot(range(24), occupancy, marker='o', color='black', linewidth=1.5, markersize=4)
plt.fill_between(range(24), occupancy, color='lightgray', alpha=0.5)
plt.title('Fig 2: 24h Parking Occupancy Trend', fontsize=12, fontweight='bold')
plt.xlabel('Hour of Day')
plt.ylabel('Occupied Spots')
plt.xticks(range(0, 24, 2))
plt.grid(True, linestyle='--', alpha=0.6)
plt.savefig('Fig2_Trend.png', dpi=300, bbox_inches='tight')

# 图 3: 空间分布 (散点图)
plt.figure(figsize=(6, 5))
plt.scatter(spots.iloc[:, 1], spots.iloc[:, 2], c='black', marker='s', s=15, label='Parking Spots')
plt.scatter(users.iloc[:, 1], users.iloc[:, 2], c='gray', marker='o', s=8, alpha=0.5, label='User Dest.')
plt.title('Fig 3: Spatial Distribution', fontsize=12, fontweight='bold')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.legend()
plt.savefig('Fig3_Spatial.png', dpi=300, bbox_inches='tight')

# 图 4: 性能对比 (柱状图)
plt.figure(figsize=(6, 4))
labels = ['Q1 (Ideal)', 'Q2 (Offline)', 'Q3 (Online)']
counts =[300, 200, 200]
plt.bar(labels, counts, color='white', edgecolor='black', linewidth=1.5)
plt.title('Fig 4: Algorithm Performance Comparison', fontsize=12, fontweight='bold')
plt.ylabel('Served Users')
plt.savefig('Fig4_Comparison.png', dpi=300, bbox_inches='tight')

print("✅ 四张论文级黑白图表生成完毕！请查看目录下的 Fig1-Fig4.png")