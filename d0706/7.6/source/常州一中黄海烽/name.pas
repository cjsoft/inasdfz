var
   a:array[0..1,0..101000] of int64;
   zt:array[0..101000] of longint;
   ans:int64;
   i,j,t,l,r,n,m:longint;

procedure setin;
begin
    assign(input,'name.in');
    assign(output,'name.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

begin
    setin;
    read(n);
    for i:=1 to n do read(a[0,i]);
    for i:=1 to n do read(a[1,i]);
    for i:=1 to n do zt[i]:=0;
    read(m);
    for i:=1 to m do
    begin
        read(l,r,t);
        for j:=l to r do
        if a[zt[j],j]<=t then zt[j]:=zt[j] xor 1;
    end;
    ans:=0;
    for i:=1 to n do ans:=ans+a[zt[i],i];
    writeln(ans);
    outit;
end.