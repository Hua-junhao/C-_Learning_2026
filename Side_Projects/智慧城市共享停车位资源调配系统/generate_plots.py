import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

# ======= 1. 编码兼容性读取 =======
def smart_read_csv(filename):
    for encoding in ['utf-8', 'gbk', 'utf-8-sig']:
        try:
            return pd.read_csv(filename, encoding=encoding)
        except:
            continue
    raise ValueError(f"读取失败：{filename}")

alloc = smart_read_csv('q3_allocations.csv')
spots = smart_read_csv('spots.csv')
users = smart_read_csv('users.csv')

# ======= 2. 论文级绘图配置 =======
# 使用 DejaVu Sans 防乱码，开启 seaborn 的白底网格主题，色彩更现代
plt.rcParams['font.family'] = 'DejaVu Sans'
plt.rcParams['axes.unicode_minus'] = False
sns.set_theme(style="whitegrid") 

# ======= 3. 绘图与保存 =======

# --- 图 1: 步行距离分布 (天蓝色直方图 + KDE密度曲线) ---
plt.figure(figsize=(6, 4))
sns.histplot(alloc['dist'], bins=15, kde=True, color='skyblue', edgecolor='white')
plt.title('Fig 1: Walking Distance Distribution', fontsize=12, fontweight='bold')
plt.xlabel('Distance (m)')
plt.ylabel('User Count')
plt.savefig('Fig1_Distance.png', dpi=300, bbox_inches='tight')
plt.close()

# --- 图 2: 24小时停车趋势 (红色折线 + 浅红面积填充) ---
plt.figure(figsize=(6, 4))
occupancy = [alloc[(alloc['arr'] <= h) & (alloc['dep'] > h)].shape[0] for h in range(24)]
plt.plot(range(24), occupancy, marker='o', color='red', linewidth=2)
plt.fill_between(range(24), occupancy, color='red', alpha=0.1) # 浅红色填充
plt.axhline(y=300, color='black', linestyle='--', label='Total Capacity (300)') # 容量虚线
plt.title('Fig 2: 24h Parking Occupancy Trend', fontsize=12, fontweight='bold')
plt.xlabel('Hour of Day')
plt.ylabel('Occupied Spots')
plt.xticks(range(0, 24, 2))
plt.legend(loc='upper right')
plt.savefig('Fig2_Trend.png', dpi=300, bbox_inches='tight')
plt.close()

# --- 图 3: 空间分布 (绿色方块车位 + 蓝色透明圆点用户) ---
plt.figure(figsize=(6, 5))
plt.scatter(spots.iloc[:, 1], spots.iloc[:, 2], c='green', alpha=0.6, marker='s', s=20, label='Parking Spots')
plt.scatter(users.iloc[:, 1], users.iloc[:, 2], c='blue', alpha=0.2, marker='o', s=10, label='User Dest.')
plt.title('Fig 3: Spatial Distribution', fontsize=12, fontweight='bold')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.legend(loc='lower right')
plt.savefig('Fig3_Spatial.png', dpi=300, bbox_inches='tight')
plt.close()

# --- 图 4: 性能对比 (青色柱状图 + 橙色折线双坐标轴) ---
fig, ax1 = plt.subplots(figsize=(6, 4))
labels = ['Q1 (Ideal)', 'Q2 (Offline)', 'Q3 (Online)']
counts = [300, 200, 200]
dists = [2.82, 9.45, 9.47] # 平均距离数据
x = range(len(labels))

# 画柱状图 (服务人数，主坐标轴)
ax1.bar(x, counts, width=0.4, color='teal', alpha=0.7, label='Served Users')
ax1.set_ylabel('User Count', color='teal', fontsize=11, fontweight='bold')
ax1.set_xticks(x)
ax1.set_xticklabels(labels)

# 画折线图 (平均距离，副坐标轴)
ax2 = ax1.twinx()
ax2.plot(x, dists, marker='D', color='orange', linewidth=2, label='Avg Dist')
ax2.set_ylabel('Avg Distance (m)', color='orange', fontsize=11, fontweight='bold')

plt.title('Fig 4: Algorithm Performance Comparison', fontsize=12, fontweight='bold')
plt.savefig('Fig4_Comparison.png', dpi=300, bbox_inches='tight')
plt.close()

print("✅ 四张独立的【彩色高级版】图表生成完毕！")