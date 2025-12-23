import os
import shutil
from datetime import datetime

EXTENSIONS = {'.cpp', '.c', '.exe'}
EXCLUDE_DIRS = {'.git', '.vscode', '.cph', '.zencoder', '__pycache__'}

def get_date_info(file_path):
    timestamp = os.path.getmtime(file_path)
    date = datetime.fromtimestamp(timestamp)
    return date.strftime('%Y'), date.strftime('%B')

def organize_files(base_dir):
    print(f"Scanning directory: {base_dir}")
    for root, dirs, files in os.walk(base_dir):
        dirs[:] = [d for d in dirs if d not in EXCLUDE_DIRS]
        for file in files:
            if file == os.path.basename(__file__):
                continue
            _, ext = os.path.splitext(file)
            if ext.lower() in EXTENSIONS:
                source_path = os.path.join(root, file)
                year, month = get_date_info(source_path)
                target_year_dir = os.path.join(base_dir, year)
                target_month_dir = os.path.join(target_year_dir, month)
                if not os.path.exists(target_month_dir):
                    os.makedirs(target_month_dir)
                target_path = os.path.join(target_month_dir, file)
                if os.path.abspath(source_path) == os.path.abspath(target_path):
                    continue
                if os.path.exists(target_path):
                    base, extension = os.path.splitext(file)
                    counter = 1
                    while os.path.exists(target_path):
                        target_path = os.path.join(target_month_dir, f"{base}_{counter}{extension}")
                        counter += 1
                try:
                    shutil.move(source_path, target_path)
                    print(f"Moved: {file} -> {os.path.join(year, month)}")
                except Exception as e:
                    print(f"Error moving {file}: {e}")

if __name__ == "__main__":
    organize_files(os.getcwd())
