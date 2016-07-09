var  n,i,j,a0,tmp:longint; f:array [0..5001,0..5001] of boolean;
     b:array [0..5001] of longint;

function bitconunt(x:longint):longint;
begin
  bitconunt:=0;
  while x>0 do
  begin
    if x and 1=1 then inc(bitconunt);
	x:=x>>1;
  end;
end;

begin
  assign(input,'spy.in'); assign(output,'spy.out');
  reset(input); rewrite(output);
  readln(n);
  fillchar(f,sizeof(f),false);
  for i:=0 to n-1 do
  begin
	for j:=0 to n-1 do
	begin
	  if (bitconunt((i or j)xor i)+1)mod 2=1 then f[i,j]:=true;
	end;
  end;
  for i:=0 to n-1 do read(b[i]);
  a0:=0;
  for i:=0 to n-1 do inc(a0,b[i]); a0:=(a0*2)div n-b[n-1];
  write(a0);
  for i:=0 to n-1 do b[i]:=b[i]-a0;
  for i:=1 to n-1 do
  begin
    tmp:=0;
    for j:=0 to n-1 do if f[j,i] then inc(tmp,b[j]);
	tmp:=tmp*4 div n-b[n-1];
	write(' ',tmp);
  end;
  writeln;
  close(input); close(output);
end.
