
#include <afx.h>


void pressKey()
{
    keybd_event(VK_SCROLL, 0x45, 0, ULONG_PTR(0));
    keybd_event(VK_SCROLL, 0x45, KEYEVENTF_KEYUP, ULONG_PTR(0));
}


int main(
    int /*argc*/,
    char** /*argv*/)
{
    // Get the screen saver timeout (seconds).
    int ssTimeout = 0;
    SystemParametersInfo(SPI_GETSCREENSAVETIMEOUT, 0, &ssTimeout, 0);

    // Take off 10 seconds, and convert to milliseconds.
    ssTimeout -= 10;
    ssTimeout *= 1000;

    while(1)
    {
        //void Sleep(DWORD dwMilliseconds);
        Sleep(ssTimeout);

        //TODO if time after 4pm, and before 7am -> loop
        //TODO if screen saver is active (SystemParametersInfo) -> loop

        // Press the key.
        pressKey();
    }

    return EXIT_SUCCESS;
}

