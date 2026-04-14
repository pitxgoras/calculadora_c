#include <windows.h>

// Variables globales
HWND cajaNum1, cajaNum2, cajaResultado;

// Función que hace los cálculos
void Calcular(int operacion) {
    char texto1[100], texto2[100];
    double num1, num2, resultado = 0;
    
    // Leer lo que el usuario escribió
    GetWindowTextA(cajaNum1, texto1, 100);
    GetWindowTextA(cajaNum2, texto2, 100);
    
    // Convertir texto a números
    num1 = atof(texto1);
    num2 = atof(texto2);
    
    // Hacer la operación según el botón presionado
    switch(operacion) {
        case 1: // Suma
            resultado = num1 + num2;
            break;
        case 2: // Resta
            resultado = num1 - num2;
            break;
        case 3: // Multiplicación
            resultado = num1 * num2;
            break;
        case 4: // División
            if(num2 != 0)
                resultado = num1 / num2;
            else
                MessageBoxA(NULL, "No se puede dividir entre cero", "Error", MB_OK);
            break;
    }
    
    // Mostrar el resultado
    char resultadoTexto[100];
    sprintf(resultadoTexto, "%.2f", resultado);
    SetWindowTextA(cajaResultado, resultadoTexto);
}

// Manejar la ventana
LRESULT CALLBACK VentanaProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) {
        case WM_CREATE:
            // Etiqueta "Número 1"
            CreateWindowA("STATIC", "Número 1:", WS_VISIBLE | WS_CHILD, 20, 20, 80, 25, hwnd, NULL, NULL, NULL);
            // Caja para número 1
            cajaNum1 = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 20, 150, 25, hwnd, NULL, NULL, NULL);
            
            // Etiqueta "Número 2"
            CreateWindowA("STATIC", "Número 2:", WS_VISIBLE | WS_CHILD, 20, 60, 80, 25, hwnd, NULL, NULL, NULL);
            // Caja para número 2
            cajaNum2 = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 110, 60, 150, 25, hwnd, NULL, NULL, NULL);
            
            // Etiqueta "Resultado"
            CreateWindowA("STATIC", "Resultado:", WS_VISIBLE | WS_CHILD, 20, 110, 80, 25, hwnd, NULL, NULL, NULL);
            // Caja para resultado (solo lectura)
            cajaResultado = CreateWindowA("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 110, 110, 150, 25, hwnd, NULL, NULL, NULL);
            
            // Botón SUMAR
            CreateWindowA("BUTTON", "Sumar", WS_VISIBLE | WS_CHILD, 20, 160, 70, 35, hwnd, (HMENU)1, NULL, NULL);
            // Botón RESTAR
            CreateWindowA("BUTTON", "Restar", WS_VISIBLE | WS_CHILD, 100, 160, 70, 35, hwnd, (HMENU)2, NULL, NULL);
            // Botón MULTIPLICAR
            CreateWindowA("BUTTON", "Multiplicar", WS_VISIBLE | WS_CHILD, 180, 160, 70, 35, hwnd, (HMENU)3, NULL, NULL);
            // Botón DIVIDIR
            CreateWindowA("BUTTON", "Dividir", WS_VISIBLE | WS_CHILD, 260, 160, 70, 35, hwnd, (HMENU)4, NULL, NULL);
            break;
            
        case WM_COMMAND:
            // Identificar qué botón presionaron
            switch(wParam) {
                case 1: Calcular(1); break;  // Sumar
                case 2: Calcular(2); break;  // Restar
                case 3: Calcular(3); break;  // Multiplicar
                case 4: Calcular(4); break;  // Dividir
            }
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProcA(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

// Programa principal
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar la ventana
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = VentanaProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MiCalculadora";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClassA(&wc);
    
    // Crear la ventana
    HWND hwnd = CreateWindowExA(0, "MiCalculadora", "Calculadora Simple", 
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT, 370, 250,
        NULL, NULL, hInstance, NULL);
    
    if(hwnd == NULL) return 0;
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // Bucle de mensajes (mantiene la ventana abierta)
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}