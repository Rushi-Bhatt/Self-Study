declare 
no number(6);
s number(10);
j number(4);
begin
s:=0;
no:=&no;
while(no>0)
loop
j:=mod(no,10);
s:=s+j;
no:=no/100;
end loop;
dbms_output.put_line('even digit sum is '||s);
end;
/
