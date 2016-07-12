const mo=1<<30;
var
   ans,a,b,c,n:int64;
   i,j,k:longint;
   f:array[0..25000000] of longint;

procedure setin;
begin
    assign(input,'skyfall.in');
    assign(output,'skyfall.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

begin
    setin;
    read(a,b,c);
    n:=a*b*c;
    if n>25000000 then begin writeln('giligili eye~');outit;end;
    for i:=1 to n do f[i]:=0;
    for i:=1 to n do
    begin
        j:=1;
        while j*i<=n do
        begin
            inc(f[j*i]);
            inc(j);
        end;
    end;
    ans:=0;
    for i:=1 to a do
     for j:=1 to b do
      for k:=1 to c do
       ans:=(ans+f[i*j*k]) mod mo;
    writeln(ans);
    outit;
end.