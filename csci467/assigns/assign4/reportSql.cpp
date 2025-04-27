SELECT Event.EventID, Event.EventName, Event.eventDate, Event.eventTime, Event.eventStreet, Event.eventCity, Event.eventState, Event.eventZip, Event.eventCountry,
	   Artists.artistID, Artists.fName, Artists.lName, Artists.artistPhone, Artists.artistEmail,
	   Agents.agentID, Agents.fName, Agents.lName, Agents.cellPhone, Agents.email,
	   Vendor.vendorID, Vendor.companyName, Vendor.vendorType,
	   Representative.repID, Representative.fName, Representative.lName, Representative.repPhone, Representative.repEmail
	   FROM Representative
			INNER JOIN Artists on Event.ArtistID = Artists.artistID
			INNER JOIN Vendor on Event.VendorID = Vendor.vendorID
			ORDER BY Event.EventID


(Vendor INNER JOIN (Agents INNER JOIN (Artists INNER JOIN Event ON Artists.artistID = Event.ArtistID)
ON Agents.agentID = Artists.agentID) ON Vendor.vendorID = Event.VendorID) ON Representative.repID = Vendor.repID;

