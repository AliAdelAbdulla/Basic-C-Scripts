# Basic C Scripts
A collection of basic scripts written in the C programming language.

## 1. First Script:
- Reads any data from a standard input device.
- Writes it on the screen.
- Data should be of any length.

## 2. Second Script:
- Prints the day of the week
- Forks to print the date.

## 3. Third Script:
- Script A should be the server which:
    - Prints the msg received from scripts B & C
    - Replies with the msg received from script B or C.
- Script B should be a client which:
    - Sends the following msg to the server: “This is Client B.”
    - Prints the reply received from Script A.
- Script C should be a client which:
    - Sends the following msg to the server: “I am Client C.”
    - Prints the reply received from Script A.

## 4. Fourth Script:
- Creates two threads (Thread A, Thread B).
- Threads should alternate using Mutex to print the following:
    - Thread A should print numbers from 1 to 7.
    - Thread B should print numbers even numbers from 2 to 14
- The output should be in the following sequence:
1 ➔ 2 ➔ 2 ➔ 4 ➔ 3 ➔ 6 ➔ 4➔ 8➔ 5➔ 10➔ 6➔ 12➔ 7➔ 14
