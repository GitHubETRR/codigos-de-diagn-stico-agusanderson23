tareas = []

def mostrarMenu():
    print("\n--- MENU DE TAREAS ---")
    print("1. Agregar tarea")
    print("2. Ver tareas")
    print("3. Salir")
    
def agregarTarea():
    tarea = input("Escribi la tarea que quieras agregar: ")
    tareas.append(tarea)
    print("Tarea agregada correctamente")
    
def verTareas():
    if not tareas:
        print("No hay tareas agregadas")
    else:
        print("Tareas pendienres:")
        for t in tareas:
            print(t)
        
while True:
    AGREGARTAREA = "1"
    VERTAREAS = "2"
    SALIR = "3"
    
    mostrarMenu()
    opcion = input("Elegi una opcion")
    
    if opcion == "1":
        agregarTarea()
        
    elif opcion == "2":
        verTareas()
    
    elif opcion == "3":
        print("Saliendo del programa...")
        break
        
    else:
        print("Opción invalida, intente nuevamente")
