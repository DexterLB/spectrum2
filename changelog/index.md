---
layout: page
title: Spectrum 2
---

### Version 2.0.0-beta2 (2012-03-28):

**General:**

* Fixed bug when Roster Item Exchange and subscribe stanzas were sent
	repeatedly.
* Backends related logs now contain the backend PID.
* Fixed username_mask setting.
* Added new fields into statistics (backends_crashed, messages related
	stats).
* Chatstates are now not counted as incoming messages in stats.
* Log4cxx is now optional dependency. Without Log4cxx, Spectrum 2 logs
	to standard output.
* Fixed crash when Log4cxx configuration file didn't exist.
* Admin can now see "Admin" contact in server-mode.

**libpurple:**

* Added initial support for MUC for prpl-jabber protocol.

**LibCommuni IRC backend:**

* Fixed sending/receiving UTF8 messages.
* Using the [registration] auto_register=1 config option, users don't
	have to register manually when connecting IRC network.

**Skype:**

* Memory usage statistic now includes the Skype client.
* Fixed logging issue when the logs were not stored in the proper instance
	directory.
* Skype backend includes also Skype client memory usage into the account.
* Working buddies adding/removing.
* Information about missed call is now forwarded to XMPP user.
* Fixed bug when Skype client instance wasn't killed by backend.

### Version 2.0.0-beta (2012-02-28):

**General:**

* Added PostreSQL support (thanks to Jadestorm).
* Added XEP-0100 (Gateway interaction) support.
* Send presences only "from" bare JID (fixed bug with buddies appearing
	twice in the roster and potential unregistering issues).
* Fixed potential MySQL/SQLite3 deadlocks.
* Fixed disconnecting in server-mode when client does not send unavailable
	presence before disconnection.
* Fixed crash in server-mode when client send its custom jabber:iq:storage
	payload.
* Fixed registration from Pidgin.
* Unsubscribe presence sent to some buddy doesn't disconnect the account.
* Remote Roster requests are not sent to resources, but to bare JID.
* Added automatic reconnection in case of non-fatal error.
* Added more error messages.

**Skype:**

* Initial support for Skype added, read more on
	http://spectrum.im/projects/spectrum/wiki/Spectrum_2_Admin_-_Skype_backend

**SMSTools3:**

* Initial support for SMSTools3, read more on
http://spectrum.im/projects/spectrum/wiki/Spectrum_2_Admin_-_SMSTools3_backend

### version 2.0.0-alpha (2011-12-06):

**General:**

* First Spectrum 2.0.0 alpha release, check more on
	http://spectrum.im/projects/spectrum/wiki/Spectrum_200_alpha
* Rewrite using Swiften library.
