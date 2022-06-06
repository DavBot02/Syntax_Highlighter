# Actividad 5.3 Luis David López Magaña A00344656
import multiprocessing
import pathlib
import time
import os

number_of_processes = multiprocessing.cpu_count() - 1


def lexer(input_file):
    os.system(f"./main.out {input_file[:-4]}")


def sequential_lexer(input_files):
    for file in input_files:
        lexer(file)


def concurrent_lexer(input_files: list):
    pool = multiprocessing.Pool(processes=number_of_processes)
    formatted_files = []
    for file in input_files:
        formatted_files.append((file,))

    pool.starmap(lexer, formatted_files)


def compute_speedup() -> None:

    print("Fetching files...")
    files_to_check = []
    for filename in pathlib.Path("./tests/").glob('**/*.txt'):
        files_to_check.append(os.path.basename(filename))

    print("Computing...")

    os.system("g++ ./main.cpp -o main.out")

    start_time_sequential = time.time()
    sequential_lexer(files_to_check)
    finish_time_sequential = time.time()
    total_time_sequential = finish_time_sequential - start_time_sequential
    print(f"Sequential approach duration: {total_time_sequential} seconds.")

    start_time_concurrent = time.time()
    concurrent_lexer(files_to_check)
    finish_time_concurrent = time.time()
    total_time_concurrent = finish_time_concurrent - start_time_concurrent
    print(f"Concurrent approach duration: {total_time_concurrent} seconds.")

    print(f"Speedup = {total_time_sequential / total_time_concurrent}")


if __name__ == "__main__":
    compute_speedup()