Base: CanFestival-3-a82d867e7850

URL: http://www.canfestival.org/code


Notes

- Added OD pointer to timer start&stop
  + Callback did define this parameter but it was filled with NULL
  + UNTESTED on rtai/xeno
- Fix in win32 DLL generation
- Fixed warnings:
  + dfc.c: unused variable node in CheckSDOAndContinue
  + lifegrd.c: removed check in GuardTimeAlarm, like everywhere else
