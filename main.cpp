#include <windows.h>
#include <math.h>

DWORD WINAPI moveit(LPVOID lpParam) {
    HWND a = (HWND)lpParam;
    int i, j, k = 1;
    while (k++) {
        i = 200 + 300 * cos(k);
        j = 150 + 300 * sin(k);
        MoveWindow(a, i, j, 200, 200, TRUE);
        Sleep(50);
    }
    return 0;
}

int main() {
    DWORD dwThreadId;
    HWND last = GetForegroundWindow();
    ShowWindow(last, SW_HIDE);
    while (1) {
        if (last != GetForegroundWindow()) {
            last = GetForegroundWindow();
            CreateThread(NULL, 0, moveit, last, 0, &dwThreadId);
        }
    }
    return 0;
}
