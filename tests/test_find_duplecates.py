from subprocess import run, PIPE
import os
import pytest

B_PATH_FILE = './bin/find_duplecates'

def test_bin_folder_contains_find_duplecates():
    assert os.path.isfile(B_PATH_FILE)

def test_find_duplecates_not_correct_input():
    result = run([B_PATH_FILE], input="../tests/find_duplecates/file3.txt ../tests/find_duplecates/file1.txt", stderr=PIPE, stdout=PIPE)
    assert result.returncode != 0
    assert "Puck you, Verter!" in result.stderr

def test_find_duplecates_correct_input():
    file_1 = "../tests/find_duplecates/file1.txt"
    file_2 = "../tests/find_duplecates/file2.txt"
    result = run([B_PATH_FILE], input=f"{file_1} {file_2}", stdout=PIPE)
    assert os.path.isfile(file_1)
    assert os.path.isfile(file_2) == False
    assert result.stdout == ""
    assert result.returncode == 0

def test_find_duplecates_empty_files():
    file_1 = "../tests/find_duplecates/empty1.txt"
    file_2 = "../tests/find_duplecates/empty2.txt"
    result = run([B_PATH_FILE], input=f"{file_1} {file_2}", stdout=PIPE)
    assert os.path.isfile(file_1)
    assert os.path.isfile(file_2) == False
    assert result.stdout == ""
    assert result.returncode == 0

if __name__ == "__main__":
    pytest.main()
