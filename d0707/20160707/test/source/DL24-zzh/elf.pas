const chutirensb=true;
var n,l:longint;
map:array[0..40]of int64;
w:int64;
procedure init;
var s:string[41];
i,j:longint;
begin
readln(n);
fillchar(map,sizeof(map),0);
for i:=0 to n-1 do begin
	readln(s);
	for j:=1 to 40 do begin
		map[i]:=map[i]<<1;
		if s[j]='1' then map[i]:=map[i] or 1;
		end;
	end;
readln(l);
readln(s);
w:=0;
for j:=1 to l do begin
	w:=w<<1;
	if s[j]='1' then w:=w or 1;
	end;
end;

procedure naive;
var zt,i:longint;
now:int64;
ans:longint;
begin
ans:=0;
for zt:=0 to (1<<n)-1 do begin
	now:=0;
	for i:=0 to n-1 do if zt and (1<<i) <> 0 then now:=now xor map[i];
	for i:=0 to 40-l do if (now>>i) and (int64(1)<<l-1) = w then begin
		inc(ans);
		break;
		end;
	end;
writeln(ans);
close(input);
close(output);
end;


begin
assign(input,'elf.in');
assign(output,'elf.out');
reset(input);
rewrite(output);
init;
if (chutirensb) then naive;
end.
