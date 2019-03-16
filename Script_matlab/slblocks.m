function blkStruct = slblocks
		% This function specifies that the library should appear
		% in the Library Browser
		% and be cached in the browser repository

		%%Browser(1).Library = 'gearMotorLib';
		% 'mylib' is the name of the library

		%%Browser(1).Name = 'Gear Motor';
		% 'My Library' is the library name that appears 
             % in the Library Browser
        Browser.Library = 'GCU_lib';
		Browser.Name = 'GCU Library';
		blkStruct.Browser = Browser;
       