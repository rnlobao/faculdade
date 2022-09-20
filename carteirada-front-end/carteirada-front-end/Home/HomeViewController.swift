//
//  HomeViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import UIKit

class HomeViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()

        setupTableView()
    }


    func setupTableView() {
        tableView.delegate = self
        tableView.dataSource = self
        tableView.separatorStyle = .none
        tableView.allowsSelection = false
        tableView.register(UINib(nibName: "ChartTableViewCell", bundle: nil), forCellReuseIdentifier: "chart")
        tableView.register(UINib(nibName: "ClassesTableViewCell", bundle: nil), forCellReuseIdentifier: "classes")
    }

}

extension HomeViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 500
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 2
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if indexPath.row == 0 {
            let cell = tableView.dequeueReusableCell(withIdentifier: "chart", for: indexPath) as! ChartTableViewCell
            cell.setupView()
            return cell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "classes", for: indexPath) as! ClassesTableViewCell
            return cell
        }
    }
    
    
}
