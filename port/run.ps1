# Run the port for a few seconds and summarise the log (lookup misses, aborts, last lines). Usage: run.ps1 [seconds]
param([int]$Seconds = 40)
$exe = 'E:\thps64\port\build\THPS64Recomp.exe'
$rom = "E:\Tony Hawk's Pro Skater (U) (V1.1) [!].z64"
$out = 'E:\thps64\port\run.log'; $err = 'E:\thps64\port\run.err'
$env:THPS_HIDDEN = "1"; $env:THPS_WATCH = "1"; if (-not $env:THPS_TRACE_FN) { $env:THPS_TRACE_FN = "" }
$p = Start-Process $exe -ArgumentList ('"' + $rom + '"') -WorkingDirectory 'E:\thps64\port\build' `
     -RedirectStandardOutput $out -RedirectStandardError $err -PassThru
$t = 0
while (-not $p.HasExited -and $t -lt $Seconds) { Start-Sleep 1; $t++ }
if (-not $p.HasExited) { Stop-Process -Id $p.Id -Force; "still running after ${Seconds}s (stopped)" } else { "exited after ${t}s, code $($p.ExitCode)" }
"--- stdout (last 12)"; Get-Content $out -Tail 12
"--- stderr (filtered)"; Get-Content $err | Where-Object { $_ -notmatch '^\[thps\]\s{3,}' } | Select-Object -Last 25
