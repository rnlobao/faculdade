//
//  HomeViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 19/09/22.
//

import UIKit
import FirebaseAuth
import FirebaseDatabase

class HomeViewController: UIViewController {

    @IBOutlet weak var tableView: UITableView!
    
    let ref = Database.database().reference()
    let uid = Auth.auth().currentUser?.uid
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationController?.navigationBar.isHidden = true
    }
    
    override func viewDidAppear(_ animated: Bool) {
        isItUser()
        self.tabBarController?.tabBar.isHidden = false
    }
    
    func isItUser() {
        if Auth.auth().currentUser == nil {
            let myViewController = Register2ViewController()
            myViewController.modalPresentationStyle = .fullScreen
            navigationController?.pushViewController(myViewController, animated: true)
        } else {
            setupTableView()
            return
        }
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
        if indexPath.row == 0 {
            return 500
        }
        return 400
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 2
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if indexPath.row == 0 {
            let cell = tableView.dequeueReusableCell(withIdentifier: "chart", for: indexPath) as! ChartTableViewCell
            cell.setupView(acoes: false, fii: false, cripto: false)
            return cell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "classes", for: indexPath) as! ClassesTableViewCell
            cell.delegate = self
            cell.setup()
            return cell
        }
    }
    
    
}

extension HomeViewController: goToDetailScreen {
    func goToAcaoScreen() {
        let vc = DetailViewController(fii: false, stock: true, cripto: false)
        self.present(vc, animated: true)
    }
    
    func goToFiiScreen() {
        let vc = DetailViewController(fii: true, stock: false, cripto: false)
        self.present(vc, animated: true)
    }
    
    func goToCriptoScreen() {
        let vc = DetailViewController(fii: false, stock: false, cripto: true)
        self.present(vc, animated: true)
    }
}
