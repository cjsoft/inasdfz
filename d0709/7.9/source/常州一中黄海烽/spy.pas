var
    n,i,j,tt:longint;
    tmp:int64;
    a,b:array[0..5000] of int64;
    f:array[0..2510,0..2510] of boolean;

procedure setin;
begin
    assign(input,'spy.in');
    assign(output,'spy.out');
    reset(input);rewrite(output);
end;

procedure outit;
begin
    close(input);close(output);
end;

begin
    setin;
    read(n);
    fillchar(f,sizeof(f),false);
    for i:=0 to n-1 do read(b[i]);
    for i:=0 to n-1 do
    begin
        for j:=0 to n-1 do
        begin
            tmp:=i or j xor i;
            tt:=0;
            while tmp>0 do
            begin
                tt:=tt+tmp and 1;
                tmp:=tmp>>1;
            end;
            if tt and 1=0 then f[i,j]:=true;
        end;
    end;
    tmp:=0;
    for i:=0 to n-1 do tmp:=tmp+b[i];
    a[0]:=tmp*2 div n-b[n-1];write(a[0]);
    for i:=0 to n-1 do b[i]:=b[i]-a[0];
    for i:=1 to n-1 do
    begin
        tmp:=0;
        for j:=0 to n-1 do
         if f[j,i] then tmp:=tmp+b[j];
        a[i]:=tmp*4 div n-b[n-1];
        write(' ',a[i]);
    end;
    writeln;
    outit;
end.
