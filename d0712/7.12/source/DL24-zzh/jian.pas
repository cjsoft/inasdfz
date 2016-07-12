var n,m:longint;
a:array[1..10]of longint;
b:array[0..6]of boolean;
t:array[1..10]of longint;
sum:longint;
ans:longint;

function cmp:boolean;
var i:longint;
begin
for i:=1 to n do begin
	if (a[i]<>t[i]) then exit(a[i]>t[i]);
	end;
exit(false);
end;

function f(a:longint):longint;
begin
f:=a mod n;
if f=0 then f:=n;
end;


procedure check;
var i,j:longint;
begin
if sum<>m then exit;
fillchar(b,sizeof(b),false);
for i:=1 to n do begin
	if b[(a[i]+i) mod n] then exit
	else b[(a[i]+i) mod n]:=true;
	end;
for i:=1 to n-1 do begin
	for j:=1 to n do t[j]:=a[f(i+j)];
	if not cmp then exit;
	end;
inc(ans);
end;



procedure dfs(now:longint);
var i:longint;
begin
if (now=n+1) then begin
	check;
	exit;
	end;
for i:=0 to m-sum do begin
	a[now]:=i;
	inc(sum,i);
	dfs(now+1);
	dec(sum,i);
	end;
end;

begin
assign(input,'jian.in');
assign(output,'jian.out');
reset(input);
rewrite(output);
read(n,m);
dfs(1);
writeln(ans);
close(input);
close(output);
end.
