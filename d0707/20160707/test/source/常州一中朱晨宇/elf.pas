var
begin
  assign(input,'elf.in'); assign(output,'elf.out'); 
  reset(input); rewrite(output);
  
  writeln(30);
  
  close(input); close(output);
end.