estudiantes = {}

def agregar_estudiante():
    print("\nCargar estudiante")
    dni = input("DNI: ")

    if dni in estudiantes:
        print("Ese DNI ya esta cargado.")
        return

    nombre = input("Nombre: ")
    edad = int(input("Edad: "))
    nota = float(input("Nota: "))

    estudiantes[dni] = {
        "nombre": nombre,
        "edad": edad,
        "nota": nota
    }

    print("Listo, ya quedo cargado.")


def ver_estudiantes():
    print("\nEstudiantes")
    if not estudiantes:
        print("No hay nadie cargado todavia.")
        return

    for dni, datos in estudiantes.items():
        print(f"\nDNI: {dni}")
        print(f"  Nombre: {datos['nombre']}")
        print(f"  Edad: {datos['edad']}")
        print(f"  Nota: {datos['nota']}")


def borrar_estudiante():
    print("\nBorrar estudiante")
    dni = input("DNI a borrar: ")

    if dni in estudiantes:
        del estudiantes[dni]
        print("Listo, se borro.")
    else:
        print("No encontre ese DNI.")


def menu():
    while True:
        print("\nMENU")
        print("1. Cargar estudiante")
        print("2. Ver lista")
        print("3. Borrar estudiante")
        print("4. Salir")

        opcion = input("Opcion: ")

        match opcion:
            case "1":
                agregar_estudiante()
            case "2":
                ver_estudiantes()
            case "3":
                borrar_estudiante()
            case "4":
                print("Nos vemos.")
                break
            case _:
                print("Esa opcion no existe.")


menu()
