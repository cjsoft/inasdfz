var tttttt:longint;
i:longint;
procedure init;
begin
read(tttttt);
end;

begin
assign(input,'al.in');
assign(output,'al.out');
reset(input);
rewrite(output);
init;
if (tttttt=1) then writeln(-1)
else for i:=1 to tttttt do writeln(0);
close(input);
close(output);
end.
