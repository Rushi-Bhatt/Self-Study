declare
	cursor shobb is select balance from bank;
	amnt bank.balance%type;
	amntt number(8) :=0;
begin
	open shobb;
	loop
		fetch shobb into amnt;
		amntt:=amntt+amnt;
		exit when (shobb%notfound);
		dbms_output ut_line(':'||amnt);		
		
	end loop;
	dbms_output.put_line('sum is '||amntt);
end;
/

