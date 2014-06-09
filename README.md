Base: CanFestival-3-a82d867e7850

URL: http://www.canfestival.org/code


Notes
- fixed include structure (part 1)
  + Includes now refer to each other properly and there is no need for an additional include statement
  + All includes refer to <canfestival/HEADER>
- Added win32 to can_virtual driver
- Fix in win32 dll for uvccm
- Added OD pointer to timer start&stop
  + Callback did define this parameter but it was filled with NULL
  + UNTESTED on rtai/xeno
- Fix in win32 DLL generation
- Fixed warnings:
  + dfc.c: unused variable node in CheckSDOAndContinue
  + lifegrd.c: removed check in GuardTimeAlarm, like everywhere else

