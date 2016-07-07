uses math;
var ttt,tttt,n:longint;
id:array[1..2000]of longint;
kind:array[1..2000]of boolean;
id_max:longint;

procedure getchar(var c:char);
begin
c:=' ';
while (c<>'E') and (c<>'L') do read(c);
end;


procedure init;
var i:longint;
c:char;
begin
n:=0;
while n=0 do readln(n);
id_max:=0;
for i:=1 to n do begin
	getchar(c);
	kind[i]:=(c='E');
	read(id[i]);
	id_max:=max(id_max,id[i]);
	end;
end;

procedure mian;
var i:longint;
tmp,now:longint;
c:char;
begin
init;
for i:=2 to n do if (id[i]=id[i-1]) and (kind[i]=kind[i-1]) then begin
	writeln('OTHER');
	exit;
	end;
tmp:=0;
now:=0;
for i:=1 to n do begin
	if kind[i] then inc(now) else dec(now);
	tmp:=min(tmp,now);
	end;
if tmp<0 then writeln(tmp+now) else writeln(now);
end;

begin
assign(input,'probe.in');
assign(output,'probe.out');
reset(input);
rewrite(output);
read(ttt);
for tttt:=1 to ttt do mian;
close(input);
close(output);
end.
