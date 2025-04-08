import webbrowser
import time
import psutil

BASE_URL = "https://toi-coding.informatics.buu.ac.th/00-pre-toi/tasks/A3-{}/submissions"

# Loop through task numbers from 001 to 040
for i in range(1, 26):
    task_id = f"{i:03}"  # Format numbers as 001, 002, ..., 040
    url = BASE_URL.format(task_id)
    
    print(f"Opening: {url}")
    webbrowser.open(url)
    
    # Wait for 5 seconds
    time.sleep(0.5)

# # Find and close the browser process
# BROWSERS = ["chrome", "firefox", "msedge", "brave", "safari"]

# for proc in psutil.process_iter(attrs=["pid", "name"]):
#     try:
#         if any(browser in proc.info["name"].lower() for browser in BROWSERS):
#             proc.terminate()
#     except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
#         pass
