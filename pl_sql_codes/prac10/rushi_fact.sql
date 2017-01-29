 DECLARE
 fact number(9):=1;
 no number(3);
 BEGIN
 no:=&no;
while(no>=1)
loop
fact:=fact*no;
no:=no-1;
end loop;
dbms_output.put_line('ans is'||fact);
end;
/