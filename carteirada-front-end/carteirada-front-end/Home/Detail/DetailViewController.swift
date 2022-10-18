//
//  DetailViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 17/10/22.
//

import UIKit

class DetailViewController: UIViewController {
    
    var hasFii: Bool
    var hasStock: Bool
    var hasCripto: Bool
    
    init(fii: Bool, stock: Bool, cripto: Bool) {
        self.hasFii = fii
        self.hasStock = stock
        self.hasCripto = cripto
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    @IBOutlet weak var tableView: UITableView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTableView()
        self.tabBarController?.tabBar.isHidden = true
    }
    
    private func setupTableView() {
        tableView.delegate = self
        tableView.dataSource = self
        tableView.register(UINib(nibName: "ChartTableViewCell", bundle: nil), forCellReuseIdentifier: "chart")
        
        tableView.separatorStyle = .none
        tableView.allowsSelection = false
    }


}

extension DetailViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if indexPath.row == 0 {
            return 500
        }
        return 90
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "chart", for: indexPath) as! ChartTableViewCell
        cell.setupView(acoes: hasStock, fii: hasFii, cripto: hasCripto)
        return cell
    }
}
