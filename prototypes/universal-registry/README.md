# Universal Registry of Things

## Description

The Universal Registry of Things will be a trusted source of information about how to reuse objects and materials. It will do so by offering information about repair, customisation and repurposing of virtually any kind of thing.

The prototype of the Universal Registry of Things is called [ThingWiki](http://thingwiki.cc).

## Fields

*Brainstorming on [this file](fields.md)*.

Some examples of types of data to be featured:

* Manufacturer, support and end-of-life policy;
* Versions and official recalls;
* Price of object offered online (new/used);
* Materials and service manuals;
* Parts and Repair tools;
* Tutorials of repair;
* Examples of reuse / upcycling;
* Second-hand market information.

The universal registry of things was first articulated as a [concept idea](https://is.efeefe.me/concepts/universal-registry-things) within the OpenDoTT project.

![Universal Registry of Things - short video description](prototype_universal-registry.mkv)

## Examples

Examples of products to be featured in the prototype:

* Laptop
* Bicycle
* Guitar

## Prototyping Log

- **10.06.2021.** This week I bought the domain name thingwiki.cc. Now looking into setting up a wiki where I can start experimenting. 
	- I'm curious about [Wiki.js](https://js.wiki/get-started). Setting up an instance on heroku (to which I'm new also). 
	- App is up, but I still need to study a little to find how to enable it to be saved to GitHub.
	- Good documentation found [here](https://docs.requarks.io/storage/git). I had some trouble trying to have the wiki access the SSH key via path, but solved it pasting the contents of the key in the app interface. It doesn't seem to be good security, but for this prototype it's ok.
	- Yay! A clever wiki engine with automatic backup via git on markdown files! Getting excited.
	- Gave up enabling the SSL certificate for the domain name, for the time being. I'll just set up an alias to the herokuapp subdomain.
- **16.04.2021.** [meeting](../../meetings/20210416-meeting.md) with three participants. Interesting conversations, including about governance of the database.
	- Barcode, Serial Number, etc. - lots of information already exist. Manufacturers have loads of information but will not share. The identifier is there however. Parallel dataset using their identifiers.
	- Wikipedia of things? -> linux kernel of things (individual as well as institutional contributions - hobbyists, manufacturers, community repairers and those who do this for a living)
	- Focus on objects instead of people
	-  Blockchain / ledger? You are responsible for the information you add. Stewardship.
	-  Restart Project - knowledge base of objects commonly brought to repair.
	- Traceability + Readability. Ability to read / unpack.
- **13.04.2021.** [meeting](../../meetings/20210413-meeting.md) with a single participant. Deep conversations on many levels. My main takeaway: technologies have linkages to the techno-social sphere.
  - Systems view. Flows.
  - Geologists have the sense of deep history. FF Note: deep history of objects, from raw materials to disposed. Like Hesse's [Siddhartha](https://www.goodreads.com/book/show/52036.Siddhartha) becoming aware of the river.
  - Beyond learning skills, coming to trust on tools and one's abilities.
  - "Trust can not be rooted in the technical. Human, face to face. Dealing with other human beings". FF Note: add to the database the ability for people to make themselves available to be contacted by others interested on this or that object.
  - Facilitate the initial conditions, instead of driving the whole process.
  - Brainstorming on app: You pick up a tool, the app gives you solutions and directions. How to fork this thing. Here's a user story. (FF Note: I had not thought before of using an app to bring info about tools, only objects that could be transformed by tools).
- **09.04.2021,** #iotday - During the [first meeting](../../meetings/20210409-meeting.md) of reuse city lab, we have evolved the idea of the universal registry of things being not necessarily one central database, but instead a protocol/standard of information relevant for the reuse of goods and materials. It could potentially be deployed in a distributed way (such as the metadata schemes used by libraries like dublin core, perhaps?), partnering with zero waste initiatives, right to repair legislation and regulations, and other interested parties / contexts.
- **22.03.2021.** Started modelling a base in this [airtable sheet](https://airtable.com/invite/l?inviteId=inv2pca3eNBmtT4d6&inviteToken=a6a50be7ff210aebd030eefa11c11b7f11833b4be695ab35aa9eb04cd60e877e) as an experiment. An evolving list of information fields it should offer will be maintained [here](fields.md).
- I hosted a conversation at [mozfest 2021](https://is.efeefe.me/opendott/mozfest-2021). I had originally intended to focus on the universal registry of things, but spent a good part of the session contextualising my research. That informed my decision to come up with the video fragments for reuse city lab, and allow participants to decide whether they want to watch my longer depictions of activities, contexts and impressions. My session notes are [here](https://github.com/opendott-smartcities/II/blob/main/workshops/mozfest/session-notes.md). The miro board I used for the presentation is [here](https://miro.com/app/board/o9J_lQITOhI=/).
- I have secured the domain name valudata.org, thinking of potentially renaming the universal registry of things at some point. But I'm not totally convinced of it yet.

# Points of discussion

- Architecture / data structure and exchange
- Applications / Interface
- Governance / stewardship
- Policy and legislation

## References

- [Open3R](https://github.com/OpenDataManchester/Open3R) - A data standard for reporting data about Household Waste Recycling Centres
- [Dublin Core](https://dublincore.org/specifications/dublin-core/)
