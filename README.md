<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/get_next_linem.png" alt="get_next_line Banner" />
</div>

<div align="center">

# get_next_line

**Read a file descriptor line by line — like a civilized person.**

<img alt="42 badge" src="https://img.shields.io/badge/42-Project-black?style=for-the-badge" />
<img alt="Language C" src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
<img alt="Score" src="https://img.shields.io/badge/Score-125-success?style=for-the-badge" />

</div>

---

## 📌 About

`get_next_line` is a utility function that returns the next line read from a file descriptor.
It handles buffered reads internally and allows you to read from:

* Files
* Standard input
* Pipes / redirected streams

Each call returns **one line** (including the trailing `\n` if present), until EOF.

---

## ✅ Features

* Reads **one line per call** from a given `fd`
* Uses a static buffer to keep unread leftovers
* Works with **any file descriptor** (including `stdin`)
* Handles variable `BUFFER_SIZE`
* Returns `NULL` on EOF or error

---

## 🧠 Function Prototype

```c
char *get_next_line(int fd);
```

### Return Values

* **A line** read from `fd` (includes `\n` if it ended with newline)
* **NULL** if there is nothing more to read, or if an error occurs

---

## ⚙️ BUFFER_SIZE

`BUFFER_SIZE` controls how many bytes are read per `read()` call.

Example compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

> If `BUFFER_SIZE` is too small: more `read()` calls.
> If too large: more memory per buffer.

---

## 🚀 Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 🧪 Testing Tips

* Test with:

  * Empty file
  * Single line without `\n`
  * Multiple lines
  * Huge lines (bigger than `BUFFER_SIZE`)
  * `stdin`:

```bash
./a.out < file.txt
```

* Test multiple FDs (bonus) by alternating reads between two files.

---

## 🧷 Common Pitfalls

* Forgetting to `free()` returned lines → **memory leak**
* Not handling the last line without `\n`
* Incorrect leftover handling when newline is found
* Returning empty string instead of `NULL` at EOF


