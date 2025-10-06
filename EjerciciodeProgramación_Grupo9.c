#include <stdio.h>
int main() {
    int id;
    char nombre[100];
    int stock;
    float precio;
    float ganancias = 0.0;
    int opcion, cantidadVenta, cantidadReabastecer, i;
    float descuento, precioFinal;
    int productoRegistrado = 0;
    
    printf("   SISTEMA DE GESTION DE VENTAS - TIENDA\n");
    printf("==============================================\n\n");
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Consultar informacion del producto\n");
        printf("5. Ver ganancias totales\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("\n--- REGISTRAR PRODUCTO ---\n");
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                while(getchar() != '\n');
                
                printf("Ingrese el nombre del producto: ");
                scanf("%s", nombre);
                
                printf("Ingrese la cantidad en stock: ");
                scanf("%d", &stock);
                while(getchar() != '\n');
                
                while(stock < 0) {
                    printf("Error: El stock no puede ser negativo.\n");
                    printf("Ingrese la cantidad en stock: ");
                    scanf("%d", &stock);
                    while(getchar() != '\n'); 
                }
                
                printf("Ingrese el precio unitario: ");
                scanf("%f", &precio);
                while(getchar() != '\n'); 
                
                // Validación de precio negativo
                while(precio < 0) {
                    printf("Error: El precio no puede ser negativo.\n");
                    printf("Ingrese el precio unitario: ");
                    scanf("%f", &precio);
                    while(getchar() != '\n'); // Limpiar buffer
                }
                
                productoRegistrado = 1;
                printf("\n¡Producto registrado exitosamente!\n");
                break;
                
            case 2:
                // Vender producto
                if(!productoRegistrado) {
                    printf("\nError: Debe registrar un producto primero.\n");
                    break;
                }
                
                printf("\n--- VENDER PRODUCTO ---\n");
                printf("Producto: %s\n", nombre);
                printf("Stock disponible: %d unidades\n", stock);
                printf("Precio unitario: $%.2f\n", precio);
                
                printf("\nIngrese la cantidad a vender: ");
                scanf("%d", &cantidadVenta);
                
                // Validación de cantidad negativa
                if(cantidadVenta < 0) {
                    printf("Error: No se puede vender una cantidad negativa.\n");
                    break;
                }
                
                // Validación de stock suficiente
                if(cantidadVenta > stock) {
                    printf("Error: Stock insuficiente. Solo hay %d unidades disponibles.\n", stock);
                    break;
                }
                
                // Preguntar por descuento
                printf("¿Desea aplicar un descuento? (0 para no aplicar): ");
                scanf("%f", &descuento);
                
                // Validar descuento
                if(descuento < 0 || descuento > 100) {
                    printf("Descuento invalido. No se aplicara descuento.\n");
                    descuento = 0;
                }
                
                // Calcular precio con descuento
                precioFinal = precio * (1 - descuento / 100);
                
                // Realizar venta
                stock -= cantidadVenta;
                float gananciaVenta = cantidadVenta * precioFinal;
                ganancias += gananciaVenta;
                
                printf("\n--- VENTA REALIZADA ---\n");
                printf("Cantidad vendida:\t%d unidades\n", cantidadVenta);
                printf("Precio unitario:\t$%.2f\n", precio);
                if(descuento > 0) {
                    printf("Descuento aplicado:\t%.2f%%\n", descuento);
                    printf("Precio final:\t\t$%.2f\n", precioFinal);
                }
                printf("Total de venta:\t\t$%.2f\n", gananciaVenta);
                printf("Stock restante:\t\t%d unidades\n", stock);
                break;
                
            case 3:
                // Reabastecer stock
                if(!productoRegistrado) {
                    printf("\nError: Debe registrar un producto primero.\n");
                    break;
                }
                
                printf("\n--- REABASTECER STOCK ---\n");
                printf("Stock actual: %d unidades\n", stock);
                printf("Ingrese la cantidad a agregar: ");
                scanf("%d", &cantidadReabastecer);
                
                // Validación de cantidad negativa
                if(cantidadReabastecer < 0) {
                    printf("Error: No se puede agregar una cantidad negativa.\n");
                    break;
                }
                
                stock += cantidadReabastecer;
                printf("Stock reabastecido exitosamente.\n");
                printf("Nuevo stock: %d unidades\n", stock);
                break;
                
            case 4:
                // Consultar información
                if(productoRegistrado) {
                    printf("\nError: Debe registrar un producto primero.\n");
                    break;
                }
                
                printf("\n--- INFORMACION DEL PRODUCTO ---\n");
                printf("ID:\t\t\t%d\n", id);
                printf("Nombre:\t\t\t%s\n", nombre);
                printf("Stock actual:\t\t%d unidades\n", stock);
                printf("Precio unitario:\t$%.2f\n", precio);
                printf("Ganancias totales:\t$%.2f\n", ganancias);
                break;
                
            case 5:
                // Ver ganancias
                printf("\n--- GANANCIAS TOTALES ---\n");
                printf("Total de ganancias acumuladas: $%.2f\n", ganancias);
                break;
                
            case 6:
                // Salir
                printf("\n¡Gracias por usar el sistema! Hasta pronto.\n");
                break;
                
            default:
                printf("\nOpcion invalida. Por favor seleccione una opcion del 1 al 6.\n");
        }
        
    } while(opcion != 6);
    
    return 0;
}