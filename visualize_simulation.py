import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

df = pd.read_csv("positions.csv")

bodies = df['body'].unique()

colors = {
    body: plt.cm.jet(i / len(bodies))
    for i, body in enumerate(bodies)
}

fig, ax = plt.subplots(figsize=(8, 8))
ax.set_aspect('equal')
ax.set_title("N-Body Orbital Simulation")
ax.set_xlabel("X position (m)")
ax.set_ylabel("Y position (m)")

buffer = 0.2 * df[['x', 'y']].abs().max().max()
ax.set_xlim(df['x'].min() - buffer, df['x'].max() + buffer)
ax.set_ylim(df['y'].min() - buffer, df['y'].max() + buffer)

scatters = {} 
trails = {}
for body in bodies:
    scatters[body], = ax.plot([], [], 'o', color=colors[body], label=body)
    trails[body], = ax.plot([], [], '-', lw=1, color=colors[body], alpha=0.5)

ax.legend()

trail_data = {body: {'x': [], 'y': []} for body in bodies}

total_frames = df['step'].nunique()
frames = range(0, total_frames, 500)  # Skip every 500 steps for speed

def update(frame):
    step_data = df[df['step'] == frame]
    for body in bodies:
        body_data = step_data[step_data['body'] == body]
        if not body_data.empty:
            x = body_data['x'].values[0]
            y = body_data['y'].values[0]
        
            scatters[body].set_data([x], [y])
            
            trail_data[body]['x'].append(x)
            trail_data[body]['y'].append(y)
            trails[body].set_data(trail_data[body]['x'], trail_data[body]['y'])
 
    return list(scatters.values()) + list(trails.values())


ani = FuncAnimation( 
    fig, update,
    frames=frames,
    interval=50,  # ms per frame (smaller = faster)
    blit=True
)

plt.tight_layout()
plt.show()
