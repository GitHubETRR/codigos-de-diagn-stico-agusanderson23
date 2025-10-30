from enum import Enum
from datetime import datetime

tareas = []

class menu(Enum):
    AGREGAR = "1"
    VER = "2"
    SALIR = "3"

def mostrarMenu():
    print("\n--- MENU DE TAREAS ---")
    print(f"{menu.AGREGAR.value}. Agregar tarea")
    print(f"{menu.VER.value}. Ver tareas")
    print(f"{menu.SALIR.value}. Salir")
    
def agregarTarea():
    tarea = input("Escribí la tarea que quieras agregar: ")
    fecha = datetime.now().strftime("%d/%m/%Y %H:%M")
    tareas.append(f"{tarea} (agregada el {fecha})")
    print("Tarea agregada correctamente.")
    
def verTareas():
    if not tareas:
        print("No hay tareas agregadas.")
    else:
        print("Tareas pendientes:")
        for t in tareas:
            print("-", t)
            
def eliminarTarea():
    if not tareas:
        print("No hay tareas pendientes")
        return

    verTareas()
    

while True:
    mostrarMenu()
    opcion = input("Elegí una opción: ")

    match opcion:
        case menu.AGREGAR.value:
            agregarTarea()
        case menu.VER.value:
            verTareas()
        case menu.SALIR.value:
            print("Saliendo del programa...")
            break
        case _:
            print("Opción inválida, intentá nuevamente.")
