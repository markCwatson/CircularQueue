<h1>Circular Queue (cqueue) Example</h1>

This is a simple example of initializing a using a circular queue per this cqueue interface. The example includes adding of elements, printing contents, etc.

<br>

This example was built on Windows using gcc/MinGW. To build and run the executable `example.exe`, you can install chocolatey (a package manager for Windows), make, and MinGW using the following commands (when running a PowerShell as admin):

<br>

```
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

choco install make
choco install mingw
```

<br>

```
#include <stdio.h>
#include "cqueue.h"


int main(int argc, int** argv)
{
    char msg;

    cqueue_s myCqueue;

    // The cqueue will contain 5 chars
    cqueue_init(&myCqueue, 5, sizeof(char), NULL);

    while(1)
    {
        printf("Enter a character (or enter 'q' to quit): ");
        scanf("%s", &msg);

        if (msg == 'q')
        {
            break;
        }

        cqueue_enque(&myCqueue, &msg);
    }

    printf("\nThe count is %d.\n", cqueue_get_size(&myCqueue));

    char peek;
    cqueue_peek(&myCqueue, &peek);
    printf("A peek into cqueue reveals \'%c\' at head.\n", peek);

    printf("Here are the contents of the cqueue: ");

    while(!cqueue_is_empty(&myCqueue))
    {
        cqueue_deque(&myCqueue, &msg);
        printf("\'%s\' ", &msg);
    }

    cqueue_close(&myCqueue);

    return 0;
}
```

<br>

<h2>Results (1):</h2>

<br>

```
Enter a character (or enter 'q' to quit): 1
Enter a character (or enter 'q' to quit): 2
Enter a character (or enter 'q' to quit): 3
Enter a character (or enter 'q' to quit): q

The count is 3.
A peek into cqueue reveals '1' at head.
Here are the contents of the cqueue: '1' '2' '3'
```

<br>

<h2>Results (2):</h2>

<br>

```
Enter a character (or enter 'q' to quit): 1
Enter a character (or enter 'q' to quit): 2
Enter a character (or enter 'q' to quit): 3
Enter a character (or enter 'q' to quit): 4
Enter a character (or enter 'q' to quit): 5
Enter a character (or enter 'q' to quit): 6
Enter a character (or enter 'q' to quit): q

The count is 5.
A peek into cqueue reveals '2' at head.
Here are the contents of the cqueue: '2' '3' '4' '5' '6'
```