declare
	cursor rushi is select marks from student;
	mar student.marks%type;
	tmar number(8) :=0;
begin
	open rushi;
	loop
		fetch rushi into mar;
		tmar:=tmar+mar;
		exit when (rushi%notfound);
				
		
	end loop;
	dbms_output.put_line('sum is '||tmar);
end;
/

