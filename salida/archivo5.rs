struct Nodo {
	let data:i32 ,
	
	let siguiente:Nodo,
	
}
fn agregarNodo (i32  valor, Nodo cabeza) {
	let nuevoNodo:Nodo=;
	
	nuevoNodo.data:=valor;
	
	nuevoNodo.siguiente:=cabeza;
	
	cabeza:=nuevoNodo;
	
	
}

fn eliminarNodo (i32  valor, Nodo cabeza) {
	let temp:Nodo=cabeza;
	prev;
	
	if (temp != NULL && temp.data == valor){
		cabeza:=temp.siguiente;
		
		free(temp);
		
		return;
	}while(temp != NULL && temp.data != valor){
		prev:=temp;
		
		temp:=temp.siguiente;
		
		
	}if (temp == NULL){
		return;
	}prev.siguiente:=temp.siguiente;
	
	free(temp);
	
	
}

fn mostrarLista (nodo: &mut Nodo) {
	while(nodo != NULL){
		print!("%d -> {}",nodo.data);nodo:=nodo.siguiente;
		
		
	}print!("NULL\n");
}

fn () main-> i32 {
	let cabeza:Nodo=NULL;
	
	let opcion:i32 ;
	
	valor;
	
	loop{
		print!("\n1. Agregar nodo\n2. Eliminar nodo\n3. Mostrar lista\n4. Salir\n");print!("Ingrese una opción: ");let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");match (opcion){
			1 => {
				print!("Ingrese el valor a agregar: ");let mut input = String::new();
				io::stdin()
				.read_line(&mut input)
				.expect("Failed to read line");agregarNodo(&cabeza,valor);
				
				break;
				
				
			}, 2 => {
				print!("Ingrese el valor a eliminar: ");let mut input = String::new();
				io::stdin()
				.read_line(&mut input)
				.expect("Failed to read line");eliminarNodo(&cabeza,valor);
				
				break;
				
				
			}, 3 => {
				print!("Lista actual: ");mostrarLista(cabeza);
				
				break;
				
				
			}, 4 => {
				print!("Saliendo del programa.\n");break;
				
				
			}, _ => {
				print!("Opción inválida.\n");
			}}
		if(opcion != 4){
			break;
		}
	}0
}

