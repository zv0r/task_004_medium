from subprocess import run, PIPE
import os
import pytest

B_PATH_FILE = './bin/cryptography'

def test_bin_folder_contains_cryptography():
    assert os.path.isfile(B_PATH_FILE)

def test_cryptography_file_doesnt_exists():
    result = run([B_PATH_FILE], input=f"123", stdout=PIPE, stderr=PIPE)
    assert result.returncode != 0
    assert "Puck you, Verter!" in result.stderr

def test_cryptography():
    file = "../tests/cryptography/chifre_me.txt"
    result = run([B_PATH_FILE], input=f"{file}", stdout=PIPE)
    assert result.stdout == ""
    file_data = run([f"cat {file}"], stdout=PIPE)
    assert file_data.stdout == "x ficmhpt m grr ifn m fvplyki m teq ndygy xky hoc"

if __name__ == "__main__":
    pytest.main()