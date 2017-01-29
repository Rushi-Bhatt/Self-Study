declare
digits number(1); 
temp number(1);
i number(1);
no1 number(9);
n_original number(9);
no2 number(9):=0;
 begin
digits:=&digits;
 no1:=&no1;
n_original:=no1;
i:=digits-1;
while(i!=-1)
loop
temp:=mod(no1,10);
no1:=no1/10;
no2:=no2+temp*power(10,i);
i:=i-1;
end loop;
dbms_output.put_line('no2 is' ||no2);
if n_original=no2 then
dbms_output.put_line('number is pelindrome');
else
dbms_output.put_line('number is not pelindrome');
end if;
end;
/