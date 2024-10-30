const MAX_STUDENTS: usize = 3;
const MAX_SUBJECTS: usize = 3;
struct Student {
	name: [char ;50],
	
	let id:i32 ,
	
	grades: [f32 ;MAX_SUBJECTS],
	
	let average:f32 ,
	
}
fn calculateAverage (student: &mut Student) {
	let sum:f32 =0;
	
	for i in 0.. MAX_SUBJECTS{
		sum += student1.grades[i];
		
		
	}student.average:=sum / MAX_SUBJECTS;
	
	
}

fn () main-> i32 {
	students: [Student;MAX_STUDENTS];
	
	for i in 0.. MAX_STUDENTS{
		print!("Enter name of student %d: {}",i + 1);let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");print!("Enter id of student %d: {}",i);let mut input = String::new();
		io::stdin()
		.read_line(&mut input)
		.expect("Failed to read line");print!("Enter grades for student %d:\n{}",i + 1);for j in 0.. MAX_SUBJECTS{
			print!("Enter grade for subject %d: {}",j + 1);let mut input = String::new();
			io::stdin()
			.read_line(&mut input)
			.expect("Failed to read line");
		}calculateAverage(&students[i]);
		
		
	}print!("\n\nDisplaying Information:\n\n");for i in 0.. MAX_STUDENTS{
		print!("Name: %s\n{}",students[i].name);print!("ID: %d\n{}",students[i].id);print!("Grades: ");for j in 0.. MAX_SUBJECTS{
			print!("%.2f {}",students[i].grades[j]);
		}print!("\nAverage: %.2f\n\n{}",students[i].average);
	}0
}

