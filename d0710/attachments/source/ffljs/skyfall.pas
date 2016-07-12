const n=5000;np=670;kkk=1 shl 30;
var z:array[0..n]of longint;
    pr,total:array[0..np]of longint;
    aa,bb,cc:longint;
    nn,b1,b2,b3,b4:longint;
    ans:int64;
    dd:int64;
    t1,t2:text;
procedure want(f1:longint);
var f2:longint;
begin
    f2:=1;
    while f1>1 do begin
        while f1 mod pr[f2]=0 do begin
            inc(total[f2]);
            f1:=f1 div pr[f2];
        end;
        inc(f2);
    end;

end;
procedure dwant(f1:longint);
var f2:longint;
begin
    f2:=1;
    while f1>1 do begin
        while f1 mod pr[f2]=0 do begin
            dec(total[f2]);
            f1:=f1 div pr[f2];
        end;
        inc(f2);
    end;

end;
begin
    assign(t1,'skyfall.in'); reset(t1);
    assign(t2,'skyfall.out'); rewrite(t2);
    for b1:=2 to n do begin
        if z[b1]=0 then begin
            //write(' ',b1);
            inc(pr[0]);
            pr[pr[0]]:=b1;
            b2:=b1*b1;
            while b2<=n do begin
                z[b2]:=1;
                inc(b2,b1);
            end;
        end;
    end;
    //writeln(pr[0]);
    read(t1,aa,bb,cc);
    ans:=0;
    for b1:=1 to aa do begin
        want(b1);
        for b2:=1 to bb do begin
            want(b2);
            for b3:=1 to cc do begin
                want(b3);
                dd:=1;
                for b4:=1 to pr[0] do if total[b4]>0 then begin
	            dd:=(dd*(total[b4]+1))mod kkk;
                end;
                ans:=(ans+dd) mod kkk;
                dwant(b3);
            end;
            dwant(b2);
        end;
        dwant(b1);
    end;
    writeln(t2,ans);
    close(t1);close(t2);
end.
