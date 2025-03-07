/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Link {
	string domain;
	string virtualAddress;
	string fullLink;
};

bool cmpLinks(const Link& a, const Link& b) {
	if (a.domain != b.domain) {
		return a.domain < b.domain;
	}
	return a.virtualAddress < b.virtualAddress;
}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	vector<Link> links;
	for (int i = 0; i < n; i++) {
		string link;
		getline(cin, link);
		
		if (link.substr(0, 7) == "http://") {
			size_t protocolEnd = link.find("://");
			size_t domainEnd = link.find("/", protocolEnd + 3);

			Link currentLink;
			currentLink.fullLink = link;
			currentLink.domain = link.substr(protocolEnd + 3, domainEnd - (protocolEnd + 3));
			currentLink.virtualAddress = link.substr(domainEnd);

			links.push_back(currentLink);
		}
	}

	sort(links.begin(), links.end(), cmpLinks);

	for (const auto& link : links) {
		cout << link.fullLink << endl;
	}
}
*/