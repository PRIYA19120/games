import tkinter as tk
from tkinter import messagebox
import subprocess
import os

class GameArena:
    def __init__(self, root):
        self.root = root
        self.root.title("FUN ZONE ARENA")
        self.root.geometry("700x600")
        self.root.config(bg="black")

        tk.Label(self.root, text="FUN ZONE ARENA",
                 font=("Arial", 28, "bold"),
                 bg="black", fg="white").pack(pady=20)

        tk.Label(self.root, text="Choose a Game",
                 font=("Arial", 16),
                 bg="black", fg="yellow").pack(pady=10)

        self.btn_frame = tk.Frame(self.root, bg="black")
        self.btn_frame.pack(pady=30)

        self.add_buttons()

    def add_buttons(self):
        tk.Button(self.btn_frame, text="ROCK PAPER SCISSORS", width=40, height=3,
                  bg="red", fg="white", font=("Arial", 12, "bold"),
                  command=lambda: self.start_game(2)).grid(row=0, column=0, pady=10, padx=10)

        tk.Button(self.btn_frame, text="TRUTH OR DARE", width=40, height=3,
                  bg="blue", fg="white", font=("Arial", 12, "bold"),
                  command=lambda: self.start_game(3)).grid(row=1, column=0, pady=10, padx=10)
        
        tk.Button(self.btn_frame, text="KBC (QUIZ)", width=40, height=3,
                  bg="green", fg="white", font=("Arial", 12, "bold"),
                  command=lambda: self.start_game(1)).grid(row=2, column=0, pady=10, padx=10)

        tk.Button(self.btn_frame, text="TIC TAC TOE", width=40, height=3,
                  bg="purple", fg="white", font=("Arial", 12, "bold"),
                  command=lambda: self.start_game(4)).grid(row=3, column=0, pady=10, padx=10)

        tk.Button(self.btn_frame, text="EXIT", width=40, height=2,
                  bg="darkred", fg="white", font=("Arial", 12, "bold"),
                  command=self.root.destroy).grid(row=4, column=0, pady=10, padx=10)

    def compile_backend(self):
        c_source = os.path.join(os.getcwd(), "4_games.c")
        exe_path = os.path.join(os.getcwd(), "heee.exe")

        if os.path.exists(exe_path):
            return exe_path

        if not os.path.exists(c_source):
            messagebox.showerror("Error", "4_games.c not found in current folder.")
            return None

        cmd = cmd = f"gcc \"{c_source}\" -o \"{exe_path}\" -mconsole"
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        if result.returncode != 0:
            messagebox.showerror("Compile Error", f"Failed to compile 4_games.c:\n{result.stderr}")
            return None

        return exe_path

    def start_game(self, game_num):
        exe_path = self.compile_backend()
        if exe_path is None:
            return

        cmd = f'start "" cmd /k "\"{exe_path}\" {game_num} & pause"'
        subprocess.Popen(cmd, shell=True)

if __name__ == "__main__":
    root = tk.Tk()
    app = GameArena(root)
    root.mainloop()